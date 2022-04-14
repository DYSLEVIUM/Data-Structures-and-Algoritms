# Write your MySQL query statement below
SELECT dept.`name` AS `Department`, rnk_table.`name` AS `Employee`, rnk_table.`salary` 
FROM
    (
        SELECT `name`, `salary`, `departmentId`,
        RANK() OVER(PARTITION BY `departmentId` ORDER BY `salary` DESC) AS rnk
        FROM `Employee`
    ) AS rnk_table
INNER JOIN `Department` AS dept
    ON rnk_table.`departmentId` = dept.`id`
WHERE rnk = 1;
