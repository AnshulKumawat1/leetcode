SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary
FROM (
    SELECT 
        e.departmentId,
        e.salary,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS salary_rank
    FROM 
        Employee e
    GROUP BY 
        e.departmentId, e.salary
) AS RankedSalaries
JOIN Employee e ON e.salary = RankedSalaries.salary AND e.departmentId = RankedSalaries.departmentId
JOIN Department d ON d.id = RankedSalaries.departmentId
WHERE 
    RankedSalaries.salary_rank <= 3
ORDER BY 
    d.name, e.salary DESC;
