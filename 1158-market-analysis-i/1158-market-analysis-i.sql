# Write your MySQL query statement below
Select user_id as buyer_id,join_date,count(item_id) as orders_in_2019 from Users left join

(select * from orders where order_date between '2019-01-01' and '2019-12-31') as ord on user_id =ord.buyer_id 

group by user_id; 
# having min(order_date)>='2019-01-01' and max(order_date)<='2019-12-31';