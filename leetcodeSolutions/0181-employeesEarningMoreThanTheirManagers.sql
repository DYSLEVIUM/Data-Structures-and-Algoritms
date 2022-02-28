# Write your MySQL query statement below
SELECT 
  employee.`name` AS `Employee`
FROM 
  `Employee` AS employee
INNER JOIN
  `Employee` AS manager
WHERE
  employee.`managerId` = manager.`id`
AND
  employee.`salary` > manager.`salary`;
