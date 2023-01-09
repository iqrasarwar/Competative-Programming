# Write your MySQL query statement below
Select user_id, CONCAT(UCASE(LEFT(name, 1)), LCASE(SUBSTRING(name, 2))) as name from Users order by user_id
