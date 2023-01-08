# Write your MySQL query statement below
Update Salary set sex = 
case when sex = 'm'
then 'f'
else 'm'
end
