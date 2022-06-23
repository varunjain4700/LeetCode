# Write your MySQL query statement below
# select customers.name as 'Customers' from customers where customers.id not in(select customerid  from orders);
select name as 'Customers' from customers c left join orders o on c.id=o.customerid where o.customerid is NULL;