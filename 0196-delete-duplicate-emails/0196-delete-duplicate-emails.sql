/* Write your T-SQL query statement below */
Delete p1 from Person p1  where p1.id in (select p1.id from person p2 where p2.id < p1.id and p2.email = p1.email);  