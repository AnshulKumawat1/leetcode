# Write your MySQL query statement below
 WITH cte AS
(SELECT DENSE_RANK() OVER(ORDER BY salary DESC) rn, salary FROM Employee)

SELECT IFNULL((SELECT DISTINCT salary FROM cte WHERE rn=2), NULL) AS SecondHighestSalary