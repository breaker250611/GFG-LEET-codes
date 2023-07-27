/* Write your T-SQL query statement below */
-- select *,Department.id as number from Employee,Department where Employee.departmentId=Department.id;


-- select departmentID,max(salary) from Employee group by departmentID;


-- select id,name,salary,Employee.departmentid from Employee,(select departmentID,max(salary) as high from Employee group by departmentID) as ext where Employee.departmentID=ext.departmentID and ext.high = employee.salary;


select Department.name as Department,yes.name as employee,yes.Salary  from Department,(select id,name,salary,Employee.departmentid from Employee,(select departmentID,max(salary) as high from Employee group by departmentID) as ext where Employee.departmentID=ext.departmentID and ext.high = employee.salary
) as yes where Department.id=yes.departmentID;