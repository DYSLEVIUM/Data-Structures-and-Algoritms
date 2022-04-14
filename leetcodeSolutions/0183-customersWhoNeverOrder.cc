# Write your MySQL query statement below
SELECT `name` AS `Customers`
FROM `Customers` AS customers
LEFT JOIN `Orders` AS orders
    ON customers.`id` = orders.`customerId`
WHERE `customerId` IS NULL;
