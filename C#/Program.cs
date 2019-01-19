using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test4
{
    class Program
    {
        static void Main(string[] args)
        {
            College mycollege = new College();
            mycollege.Name = "信息学院";
            #region  添加数据
            while (true) 
            {
                Console.WriteLine("是否在{0}添加系？y/n",mycollege.Name);
                string answer = Console.ReadLine();
                if (answer == "y" || answer == "Y")
                {
                    Department depobj = new Department();
                    Console.WriteLine("请输入系的名称：");
                    depobj.Name= Console.ReadLine();
                    Console.WriteLine("请输入系的办公地址：");
                    depobj.Address= Console.ReadLine();
                    mycollege.AddDep(depobj);              //将系添加到学院
                    while (true)
                    {
                        Console.WriteLine("是否向{0}添加班级?  y/n",depobj.Name);
                        answer = Console.ReadLine();
                        if (answer == "y" || answer == "Y")
                        {
                            clsClass clsobj = new clsClass();
                            Console.WriteLine("请输入班级名称：");
                            clsobj.Name = Console.ReadLine();
                            depobj.AddCls(clsobj);
                            while (true)
                            {
                                Console.WriteLine("是否在{0}中添加学生？y/n",clsobj.Name);
                                answer = Console.ReadLine();
                                if (answer == "y" || answer == "Y")
                                {
                                    Student stuobj = new Student();
                                    Console.WriteLine("请输入学生姓名：");
                                    stuobj.Name = Console.ReadLine();
                                    Console.WriteLine("请输入学生性别：0：男  1：女  2：未知");
                                    stuobj.Sex = (SexType)int.Parse(Console.ReadLine());
                                    Console.WriteLine("请输入学生年龄：（18-100）");
                                    stuobj.Age = int.Parse(Console.ReadLine());
                                    Console.WriteLine("请输入学生身高（单位：厘米）：");
                                    stuobj.Height = double.Parse(Console.ReadLine());
                                    Console.WriteLine("请输入学生体重（单位：公斤）：");
                                    stuobj.Weight = double.Parse(Console.ReadLine());
                                    clsobj.AddStu(stuobj);
                                }
                                else
                                    break;
                            }
                        }
                        else
                            break;
                    }
                }
                else
                    break;
            }
            #endregion

            #region 输出数据
            Console.WriteLine(mycollege.ToString());
            for (int i = 0; i < mycollege.NumberOfDeparment; i++)
            {
                Console.WriteLine(mycollege[i].DepartmentInformation());  //系的信息
                for (int j = 0; j < mycollege[i].NumberOfClasses; j++)
                {
                    Console.WriteLine(mycollege[i][j].ClassInformation()); //班的信息
                    for (int k = 0; k < mycollege[i][j].NumberOfStudent; k++)
                    {
                        Console.WriteLine(mycollege[i][j][k].StuInformation());
                    }
                }
            }
            #endregion
        }
    }
}
