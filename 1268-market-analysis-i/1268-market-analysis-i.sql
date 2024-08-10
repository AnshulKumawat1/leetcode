# Write your MySQL query statement below
with cte as(select user_id,join_date,order_date 
from users as u
left join orders  as o
on user_id=buyer_id)

select user_id as  buyer_id  ,min(join_date) as join_date,
sum(if(order_date>='2019-01-01' AND order_date<='2019-12-31' ,1,0)) as orders_in_2019 
from cte 
group by user_id
order by buyer_id;