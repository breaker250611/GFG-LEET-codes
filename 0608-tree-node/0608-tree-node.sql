# Write your MySQL query statement below
Select id , 
CASE 
WHEN p_id is NULL then 'Root'
WHEN id in(SELECT p_id from Tree) then 'Inner'
else 'Leaf'
END as type
from tree;