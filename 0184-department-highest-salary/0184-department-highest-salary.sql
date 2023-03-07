# Write your MySQL query statement below

select department.name as Department,employee.name as Employee,Salary from department inner join employee on department.id=employee.departmentId where (employee.departmentid,salary) in (select departmentId,max(salary) from employee group by departmentId);