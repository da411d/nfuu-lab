##	-=( 1 )=-
##	Редагування структури таблиць
ALTER TABLE `sqlkn16_2_mdv`.`clients` 
	ADD COLUMN `lastVisit` INT ;
ALTER TABLE `sqlkn16_2_mdv`.`references` 
	ADD COLUMN `hash` VARCHAR(15);
ALTER TABLE `sqlkn16_2_mdv`.`references` 
	CHANGE COLUMN `hash` `signature` VARCHAR(15);
ALTER TABLE `sqlkn16_2_mdv`.`references` 
	CHANGE COLUMN `signature` `signature` VARCHAR(32);
ALTER TABLE `sqlkn16_2_mdv`.`clients` 
	CHANGE COLUMN `lastVisit` `lastVisit` DATE AFTER `name`;
ALTER TABLE `sqlkn16_2_mdv`.`references` 
	DROP COLUMN `signature`;
    
##	-=( 2 )=-
##	Вставлення нового запису
INSERT INTO `sqlkn16_2_mdv`.`clients` (`name`, `adress`, `birthday`, `phone`) VALUES ('Колинюг Ю. Ю.', 'вул. Марципанова, 12/99', '1989-11-09', '+380997348451');
INSERT INTO `sqlkn16_2_mdv`.`doctors` (`name`, `adress`, `birthday`, `phone`) VALUES ('Ліневич К. З.', 'вул. Турцяна, 23/45', '1928-02-03', '+380977770000');
INSERT INTO `sqlkn16_2_mdv`.`history` (`timestamp`, `client`, `doctor`, `data`) VALUES (CURRENT_TIMESTAMP(), 5, 8, 'Зробив прививку');
INSERT INTO `sqlkn16_2_mdv`.`references` (`timestamp`, `client_id`, `doctor_id`, `data`) VALUES (CURRENT_TIMESTAMP(), 8, 7, 'Здоровий');
INSERT INTO `sqlkn16_2_mdv`.`queues` (`doctor_id`, `current_id`) VALUES (11, 3);
INSERT INTO `sqlkn16_2_mdv`.`tickets` (`client_id`, `queue_id`, `date`, `number`) VALUES (6, 3, CURRENT_TIMESTAMP(), 8);
    
##	-=( 3 )=-
##	Коригування записів
UPDATE `sqlkn16_2_mdv`.`tickets` SET `number`='5' WHERE `ticket_id`='2';
UPDATE `sqlkn16_2_mdv`.`queues` SET `current_id` = 1;
UPDATE `sqlkn16_2_mdv`.`clients` SET `phone`='+380987654321' WHERE `birthday` < '2000-01-01';
UPDATE `sqlkn16_2_mdv`.`history` SET `data`='Воскрес' WHERE `data` = 'Мертвий';

##	-=( 4 )=-
##	Вилучення записів 
DELETE FROM `sqlkn16_2_mdv`.`tickets` WHERE `client_id` = 6 AND `queue_id` = 3 AND `number` = 8;
DELETE FROM `sqlkn16_2_mdv`.`queues` WHERE `doctor_id` = 11 AND `current_id` = 255;
DELETE FROM `sqlkn16_2_mdv`.`history` WHERE `client` = 5 AND `doctor` = 8 AND `data` = 'Зробив прививку';
DELETE FROM `sqlkn16_2_mdv`.`references` WHERE `client_id` = 8 AND `doctor_id` = 7 AND `data` = 'Здоровий';
DELETE FROM `sqlkn16_2_mdv`.`clients` WHERE `name` = 'Колинюг Ю. Ю.';
DELETE FROM `sqlkn16_2_mdv`.`doctors` WHERE `name` = 'Ліневич К. З.';