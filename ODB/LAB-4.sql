## Дата і час
SELECT name, Year(lastVisit) as lastVisitedYear
FROM clients;

## Математичні функції і функції роботи з рядками;
SELECT CONCAT("Лікар ", name) as doctor, REPLACE(REPLACE(ROUND(RAND()), 1, "ВЕЗУЧИЙ"), 0, "НЕВЕЗУЧИЙ - РОЗСТРІЛЯТИ") as lucky
FROM doctors;

## Операції керування, форматування
SELECT name, IF(Year(birthday) > 1999, "НЕПОВНОЛІТНІЙ", "ПОВНОЛІТНІЙ") as adult, format(0.5 + RAND()/2, 2) as Eye
FROM clients;

## Агрегативні функції
SELECT name 
FROM doctors
ORDER BY MIN(Day(birthday));

#SELECT clients.name as clientName, doctors.name as doctorName, timestamp, data
#FROM `references`
#INNER JOIN doctors ON `references`.doctor_id = doctors.doctor_id
#INNER JOIN clients ON `references`.client_id = clients.client_id;