
Select t1.score, (Select count(DISTINCT(t2.score))   from Scores t2 where t1.score<=t2.score) as rank from Scores t1 order by t1.score DESC;