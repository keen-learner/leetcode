/*

Write a SQL query to get the nth highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the nth highest salary 
where n = 2 is 200. If there is no nth highest salary, then the 
query should return null.

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+

*/

/*
# SOLUTION 1

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select ifnull((select distinct Salary from Employee order by Salary desc limit N,1),null)
  );
END

*/

/*
# SOLUTION 2
# Subquery: SELECT COUNT(DISTINCT(Emp2.Salary)) FROM Employee Emp2 WHERE Emp2.Salary > Emp1.Salary)

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
     # Write your MySQL query statement below.
     SELECT MAX(Salary) 
            FROM Employee Emp1
            WHERE (N-1) = ( 
                 SELECT COUNT(DISTINCT(Emp2.Salary))
                        FROM Employee Emp2
                        WHERE Emp2.Salary > Emp1.Salary)
  );
END
*/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

  RETURN (    
      SELECT e1.Salary
      FROM (SELECT DISTINCT Salary FROM Employee) e1
      WHERE (SELECT COUNT(*) FROM ((SELECT DISTINCT Salary FROM Employee) e2) WHERE e2.Salary > e1.Salary) = N - 1      
      LIMIT 1 
  );
END



