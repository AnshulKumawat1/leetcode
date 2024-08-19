# Write your MySQL query statement below
select machine_id,round(avg(tot),3) as processing_time from(
select machine_id,next-timestamp as tot from(
select machine_id,activity_type,timestamp,process_id,
lead(timestamp) over(order by machine_id,process_id,activity_type) as next
from activity
) as ak
where activity_type='start') as ak
group by machine_id



