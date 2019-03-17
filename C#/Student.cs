using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test4
{
    /// <summary>
    /// 学生类
    /// </summary>
    class Student
    {
        /// <summary>
        /// 学生姓名
        /// </summary>
        public string Name;
        /// <summary>
        /// 学生年龄
        /// </summary>
        private int age;
        /// <summary>
        /// 学生性别
        /// </summary>
        public SexType Sex;
        /// <summary>
        /// 学生身高
        /// </summary>
        public double Height;
        /// <summary>
        /// 学生体重
        /// </summary>
        public double Weight;

        /// <summary>
        /// 带参数的构造函数
        /// </summary>
        /// <param name="name">姓名</param>
        /// <param name="age">年龄</param>
        /// <param name="sex">性别</param>
        /// <param name="height">身高</param>
        /// <param name="weight">体重</param>
        public Student(string name, int age, SexType sex, double height, double weight)
        {
            Name=name;
            Sex = sex;
            Age = age;
            Height = height;
            Weight = weight;
        }
        /// <summary>
        /// 不带参数构造函数
        /// </summary>
        public Student()
        {
            Name = "";
            Sex = SexType.未知;
            Age = 20;
            Height =165.0;
            Weight = 65.0;
        }

        /// <summary>
        /// 年龄属性
        /// </summary>
        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                if (value > 100)
                    age = 100;
                else if (value < 15)
                    age = 15;
                else
                    age = value;
            }
        }

        /// <summary>
        /// 学生信息
        /// </summary>
        public string StuInformation()
        {
            string str="";
            str += "              姓名：" + Name;
            str += "    性别：" + Sex.ToString();
            str += "    年龄：" + Age.ToString();
            str += "    身高：" + Height.ToString();
            str += "    体重：" + Weight.ToString()+"\n";
            return str;
        }
    }
}
