# Write your MySQL query statement below
SELECT s1.id,s2.student from Seat s1 cross join Seat s2 where (s1.id Mod 2=0 and s1.id-1=s2.id) or (s1.id MOD 2 = 1 and s1.id+1 = s2.id) or (s1.id = (select count(id) from seat) and s2.id = s1.id
 and s1.id MOD 2 = 1) order by 1; 