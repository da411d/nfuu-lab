<?php
abstract class AbstractBooksList {
	abstract function add($item);
	abstract function delete($id);
	abstract function search($author);
	abstract function list();
}

class BooksList extends AbstractBooksList {
	private $list = [];
	
	static function genId() {
		return "BOOK." . time() . "." . rand(111111, 999999);
	}
	
	function add($item) {
		$this->list[] = $item;
	}
	
	function delete($id) {
		$this->list = array_filter($this->list, function($item) use ($id){
			return $item->id != $id;
		});
	}
	
	function search($author) {
		return array_filter($this->list, function($item) use ($author){
			return $item->author === $author;
		});
	}
	
	function list() {
		return $this->list;
	}
}

class BooksListProxy extends AbstractBooksList {
	function __construct(){
		$this->list = new BooksList();
	}
	
	function add($item) {
		if(!$item->id){
			$item->id = BooksList::genId();
		}
		return $this->list->add($item);
	}
	
	function delete($id) {
		return $this->list->delete($id);
	}
	
	function search($author) {
		return $this->list->search($author);
	}
	
	function list() {
		return $this->list->list();
	}
}
