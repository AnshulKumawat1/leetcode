# Write your MySQL query statement below.
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT Salary 
    FROM (
      SELECT Salary, DENSE_RANK() OVER (ORDER BY Salary DESC) AS ranking
      FROM Employee
    ) AS ranked_salaries
    WHERE ranking = N
    LIMIT 1
  );
END;