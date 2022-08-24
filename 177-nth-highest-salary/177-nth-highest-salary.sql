CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare m int;
set m=n-1;
 # limit operator can't handle arithmetic operations so handle it by yourself before
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary as getNthHighestSalary from employee order by salary desc limit m,1
      
  );
END