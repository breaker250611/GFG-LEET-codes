# Write your MySQL query statement below
update salary 
set 
sex = CASe sex 
when 'm' then 'f'
 else 'm'
 end;