CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`clients` (
  `client_id` INT NOT NULL AUTO_INCREMENT,
  `name` TEXT NULL,
  `adress` TEXT NULL,
  `birthday` DATE NULL,
  `phone` TEXT NULL,
  PRIMARY KEY (`client_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;

CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`doctors` (
  `doctor_id` INT NOT NULL AUTO_INCREMENT,
  `name` TEXT NULL,
  `adress` TEXT NULL,
  `birthday` TEXT NULL,
  `phone` TEXT NULL,
  PRIMARY KEY (`doctor_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;

CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`history` (
  `item_id` INT NOT NULL AUTO_INCREMENT,
  `timestamp` TIMESTAMP NULL,
  `client_id` INT NULL,
  `doctor_id` INT NULL,
  `data` TEXT NULL,
  PRIMARY KEY (`item_id`),
  INDEX `client_id_idx` (`client_id` ASC),
  INDEX `doctor_id_idx` (`doctor_id` ASC),
  CONSTRAINT `client_id`
    FOREIGN KEY (`client_id`)
    REFERENCES `sqlkn16_2_mdv`.`clients` (`client_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `doctor_id`
    FOREIGN KEY (`doctor_id`)
    REFERENCES `sqlkn16_2_mdv`.`doctors` (`doctor_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;






CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`references` (
  `reference_id` INT NOT NULL AUTO_INCREMENT,
  `client_id` INT NULL,
  `doctor_id` INT NULL,
  `timestamp` TIMESTAMP NULL,
  `data` TEXT NULL,
  PRIMARY KEY (`reference_id`),
  INDEX `client_id_idx` (`client_id` ASC),
  INDEX `doctor_id_idx` (`doctor_id` ASC),
  CONSTRAINT `client_id1`
    FOREIGN KEY (`client_id`)
    REFERENCES `sqlkn16_2_mdv`.`clients` (`client_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `doctor_id1`
    FOREIGN KEY (`doctor_id`)
    REFERENCES `sqlkn16_2_mdv`.`doctors` (`doctor_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;



CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`queues` (
  `queue_id` INT NOT NULL,
  `doctor_id` INT NULL,
  `current_id` INT NULL,
  PRIMARY KEY (`queue_id`),
  INDEX `doctor_id_idx` (`doctor_id` ASC),
  CONSTRAINT `doctor_id2`
    FOREIGN KEY (`doctor_id`)
    REFERENCES `sqlkn16_2_mdv`.`doctors` (`doctor_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;



CREATE TABLE IF NOT EXISTS `sqlkn16_2_mdv`.`tickets` (
  `ticket_id` INT NOT NULL AUTO_INCREMENT,
  `client_id` INT NULL,
  `queue_id` INT NULL,
  `date` TIMESTAMP NULL,
  `number` INT NULL,
  PRIMARY KEY (`ticket_id`),
  INDEX `client_id_idx` (`client_id` ASC),
  INDEX `queue_id_idx` (`queue_id` ASC),
  CONSTRAINT `client_id2`
    FOREIGN KEY (`client_id`)
    REFERENCES `sqlkn16_2_mdv`.`clients` (`client_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `queue_id`
    FOREIGN KEY (`queue_id`)
    REFERENCES `sqlkn16_2_mdv`.`queues` (`queue_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET cp1251 COLLATE cp1251_bin;
