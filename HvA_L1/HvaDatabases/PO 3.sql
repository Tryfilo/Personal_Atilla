CREATE TABLE `Voorraad`
(
	`product_id` INT NOT NULL,
    `soort` VARCHAR(20), 
	`hoeveelheid` INT NOT NULL,
    `houdbaarheid` VARCHAR(20),
    PRIMARY KEY (`product_id`)
);

INSERT INTO `Voorraad` (product_id, soort, hoeveelheid, houdbaarheid)
VALUES ('69', 'groente', '420', 'gekoeld');

SELECT `personeelsnummer` FROM `Werknemer`
WHERE `voornaam` = 'John'
AND `achternaam` = 'Cena';

SELECT `datum_levering` FROM `Leverancier`
WHERE `naam` LIKE '%a%'; 

SELECT `personeelsnummer` + `telefoonnummer` AS `berekening` FROM `Werknemer`;

SELECT SUM(`id`) FROM `Leverancier`;

SELECT `postcode` FROM `Klant`
GROUP BY `postcode`;

SELECT * FROM `Werknemer`
INNER JOIN `Supermarkt` ON `filiaalnummer` AND `naam` = `Supermarkt_filiaalnummer` AND `Supermarkt_naam`;