# Write your MySQL query statement below

Select d.activity_date as day ,count(Distinct(d.user_id))as active_users from
(Select * from Activity where activity_date between '2019-06-28' and '2019-07-27') as d group by d.activity_date;