/* Write your T-SQL query statement below */
select name as Customers from Customers as cu LEFT JOIN Orders as ord on cu.id = ord.customerId where ord.id is NULL; 