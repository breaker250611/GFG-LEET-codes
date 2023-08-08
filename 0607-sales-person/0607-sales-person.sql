# Write your MySQL query statement below
Select name from Salesperson 
Where name NOT IN
(SELECT sl.name from (Orders as ord left join Company as com on ord.com_id=com.com_id) left join salesperson as sl on ord.sales_id = sl.sales_id  where com.name = 'RED')  ;