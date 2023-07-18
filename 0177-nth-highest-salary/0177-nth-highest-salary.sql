CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
# DECLARE M INT;
# SET M = N;
  RETURN (
      SELECT DISTINCT salary FROM Employee Emp1 WHERE (N-1) = ( SELECT COUNT(DISTINCT(Emp2.Salary))FROM Employee Emp2 WHERE Emp2.Salary > Emp1.Salary)
  );
END