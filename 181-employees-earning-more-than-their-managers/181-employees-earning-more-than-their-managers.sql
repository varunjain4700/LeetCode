# Write your MySQL query statement below
# select name as 'Employee' from employee e where salary>(select salary from employee where id=e.managerid);

select e1.name as 'Employee' from employee e1 join employee e2 on e1.managerid=e2.id where e1.salary>e2.salary; 