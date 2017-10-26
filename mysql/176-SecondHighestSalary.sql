/*

Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the query should return 200 as 
the second highest salary. If there is no second highest salary, then 
the query should return null.

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

*/

/*
# as second required, else gives error "Every derived table must have its own alias"
# foll. gives error in case table has 1 entry
select min(second.Salary) as SecondHighestSalary from ((select distinct salary from Employee order by Salary desc limit 2 ) as second); 
*/

/*
# SOLUTION 1

Select MAX(Salary) as SecondHighestSalary 
From Employee 
Where Salary < (Select MAX(Salary) from Employee);
*/

/*
# SOLUTION 2

select max(salary) as SecondHighestSalary
from employee
where salary NOT IN (select max(salary)
from employee)

# OR
SELECT (SELECT MAX(Salary) 
FROM Employee 
WHERE Salary 
NOT IN (SELECT MAX(Salary) FROM Employee)) SecondHighestSalary;
*/

/*
# WRONG SOLUTION 3
SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1;
This gives error for 1 row table        

*/

/*
# SOLUTION 3
# NOTE: LIMIT 1,1 == LIMIT 1 OFFSET 1

SELECT
    (SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) 
    AS SecondHighestSalary;
*/


/*
# SOLUTION 4
SELECT 
    (SELECT Salary FROM Employee GROUP BY Salary ORDER BY Salary DESC LIMIT 1,1) 
    SecondHighestSalary;
*/

SELECT
    IFNULL( (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1),NULL) 
    AS SecondHighestSalary
