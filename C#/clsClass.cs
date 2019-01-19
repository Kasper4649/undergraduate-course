/// ///////////////////////////////////////////////////////////////////////////
/// 班级类的定义
/// 设计者：王宏刚
/// 建立日期：2017-10-10
/// ////////////////////////////////////////////////////////////////////////////
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test4
{
    class clsClass
    {
        /// <summary>
        /// 班级名称
        /// </summary>
        public string Name;
        /// <summary>
        /// 班级人数
        /// </summary>
        private int numberofstudent;
        /// <summary>
        /// 存储学生的数组
        /// </summary>
        private Student[] StuArray;
        /// <summary>
        /// 不带参数的构造函数
        /// </summary>
        public clsClass()
        {
            Name = "";
            numberofstudent = 0;
            StuArray = new Student[50];
        }
        /// <summary>
        /// 带参数的构造函数
        /// </summary>
        /// <param name="name"></param>
        public clsClass(string name)
        {
            Name = name;
            numberofstudent = 0;
            StuArray = new Student[50];
        }
        /// <summary>
        /// 索引
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public Student this[int index]
        {
            get {
                return index >= 0 && index < numberofstudent ?  StuArray[index] :  null;
            }
        }

        /// <summary>
        /// 班级学生人数
        /// </summary>
        public int NumberOfStudent
        {
            get
            {
                return numberofstudent;
            }
        }

        /// <summary>
        /// 男同学人数
        /// </summary>
        public int NumberOfBoy
        {
            get
            {
                int sum = 0;
                for (int i = 0; i < numberofstudent; i++)
                    if (StuArray[i].Sex == SexType.男)
                        sum++;
                return sum;
            }
        }

        /// <summary>
        /// 女同学人数
        /// </summary>
        public int NumberOfGirl
        {
            get
            {
                int sum = 0;
                for (int i = 0; i < numberofstudent; i++)
                    if (StuArray[i].Sex == SexType.女)
                        sum++;
                return sum;
            }
        }

        /// <summary>
        /// 添加一个学生，在数组的尾部加入
        /// </summary>
        /// <param name="objStu">学生对象</param>
        /// <returns>加入成功，返回true；不成功则返回false</returns>
        public bool AddStu(Student objStu)
        {
            if (numberofstudent == StuArray.Length)
                return false;
            StuArray[numberofstudent] = objStu;
            numberofstudent++;
            return true;
        }

        /// <param name="name">学生姓名</param>
        /// <param name="sex">学生性别</param>
        /// <param name="age">学生年龄</param>
        /// <param name="height">学生身高</param>
        /// <param name="weight">学生体重</param>
        /// <returns>加入成功，返回true；不成功则返回false</returns>
        public bool AddStu(string name, SexType sex, int age, double height, double weight)
        {
            Student objStu = new Student(name, age, sex, height, weight);
            return AddStu(objStu);
        }

        /// <summary>
        /// 根据学生的姓名查找学生对象
        /// </summary>
        /// <param name="Name">学生姓名</param>
        /// <param name="index">对象在数组的索引，若没有找到则返回-1</param>
        /// <returns></returns>
        public Student FindStu(string Name,ref int index)
        {
            for (int i = 0; i < numberofstudent; i++)
            {
                if (StuArray[i].Name == Name)
                {
                    index = i;
                    return StuArray[i];
                }
            }
            index = -1;
            return null;
        }

        /// <summary>
        /// 删除一个学生
        /// </summary>
        /// <param name="objStu">学生对象</param>
        /// <returns></returns>
        public bool DelStu(Student objStu)
        {
            int index = -1;
            for (int i = 0; i < numberofstudent; i++)
            {
                if (StuArray[i] == objStu)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                return false;
            if (index == numberofstudent - 1)
            {
                StuArray[index] = null;
                numberofstudent--;
                return true;
            }
            for (int i = index; i < numberofstudent; i++)
            {
                StuArray[i] = StuArray[i + 1];
            }
            numberofstudent--;
            return true;
        }

        /// <summary>
        /// 根据学生的姓名删除学生
        /// </summary>
        /// <param name="Name">学生姓名</param>
        /// <returns>成功：true   不成功：false</returns>
        public bool DelStu(string Name)
        {
            int index=-1;
            Student objStu = FindStu(Name, ref index);
            return DelStu(objStu);
        }

        /// <summary>
        /// 获取班级信息
        /// </summary>
        /// <returns></returns>
        public string ClassInformation()
        {
            string str = "";
            str = str + "          班级名称：" + this.Name;
            str = str + "   学生数：" + this.NumberOfStudent;
            str = str + "   男同学数：" + this.NumberOfBoy;
            str = str + "   女同学数：" + this.NumberOfGirl+"\n";
            return str;
        }
    }
}
