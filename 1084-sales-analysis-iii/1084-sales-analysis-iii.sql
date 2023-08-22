# Write your MySQL query statement below
Select product_id,product_name from Product where product_id IN
(Select product_id from Sales group by product_id
having min(sale_date) >= '2019-01-01' and max(sale_date) <=' 2019-03-31')