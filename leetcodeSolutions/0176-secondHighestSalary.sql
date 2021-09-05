# Write your MySQL query statement below

# common table expression solution // doesn't return null as when rank is not present
# WITH TMP AS(
#     SELECT Salary, DENSE_RANK() OVER (ORDER BY Salary DESC) as DENSERANK FROM Employee
# )
# SELECT Salary AS SecondHighestSalary FROM TMP WHERE TMP.DENSERANK=2;

# this will give wrong answer if any salary before the nth one is repeated
# WITH TMP AS(
#     SELECT Salary, ROW_NUMBER() OVER (ORDER BY Salary DESC) as ROWNUMBER FROM Employee
# )
# SELECT Salary AS SecondHighestSalary FROM TMP WHERE TMP.ROWNUMBER=2;

# The query returns the first row after n-1 row(s) so you get the nth highest record
# SELECT 
#     *
# FROM
#     table_name
# ORDER BY column_name DESC
# LIMIT n - 1, 1;

# LIMIT Doesn't return null if it is out of bound (causes error)

# SELECT Salary AS SecondHighestSalary FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee) ORDER BY Salary DESC LIMIT 1;

# SELECT Salary AS SecondHighestSalary FROM Employee ORDER BY Salary DESC LIMIT 1, 1;

# SELECT MAX(Salary) AS SecondHighestSalary FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee);

# n-1 = (2-1) = 1 
# this also doesn't return null when the count is not present
# SELECT Salary AS SecondHighestSalary FROM Employee E1 WHERE 1 = (SELECT COUNT(DISTINCT Salary) FROM Employee E2 WHERE E2.Salary > E1.Salary);

SELECT MAX(Salary) AS SecondHighestSalary FROM Employee WHERE Salary NOT IN (SELECT MAX(Salary) FROM Employee);
