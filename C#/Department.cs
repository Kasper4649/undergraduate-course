using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test4
{
    class Department
    {
        public string Name;
        public string Address;
        private int numberofclass = 0;
        private clsClass[] classArray;
        /// 不带参数的构造函数
        /// </summary>
        public Department()
        {
            Name = "";
            Address = "";
            classArray = new clsClass[10];
        }
        /// <summary>
        /// 带参数的构造函数
        /// </summary>
        /// <param name="name">系名称</param>
        /// <param name="address">系地址</param>
        public Department(string name,string address)
        {
            Name =name;
            Address =address;
            classArray = new clsClass[10];
        }
        /// <summary>
        /// 全系学生人数
        /// </summary>
        public int NumberOfStudent
        {
            get {
                int sum = 0;
                for (int i = 0; i < numberofclass; i++)
                    sum += classArray[i].NumberOfStudent;
                return sum;
            }
        }
        /// <summary>
        /// 全系男同学人数
        /// </summary>
        public int NumberOfBoy
        {
            get {
                int sum = 0;
                for (int i = 0; i < numberofclass; i++)
                    sum += classArray[i].NumberOfBoy;
                return sum;
            }
        }
        /// <summary>
        /// 全系女同学人数
        /// </summary>
        public int NumberOfGirl
        {
            get
            {
                int sum = 0;
                for (int i = 0; i < numberofclass; i++)
                    sum += classArray[i].NumberOfGirl;
                return sum;
            }
        }
        /// <summary>
        /// 班级数量
        /// </summary>
        public int NumberOfClasses
        {
            get
            {
                return numberofclass;
            }
        }
        /// <summary>
        /// 增加一个班级
        /// </summary>
        /// <param name="clsobj">班级对象</param>
        /// <returns>成功：true    失败：false</returns>
        public bool AddCls(clsClass clsobj)
        {
            if (numberofclass == classArray.Length)
                return false;
            classArray[numberofclass] = clsobj;
            numberofclass++;
            return true;
        }
        /// <summary>
        /// 增加一个班级
        /// </summary>
        /// <param name="name">班级名称</param>
        /// <returns>成功：true    失败：false</returns>
        public bool AddCls(string name)
        {
            clsClass clsobj = new clsClass(name);
            return AddCls(clsobj);
        }
        /// <summary>
        /// 删除一个班级
        /// </summary>
        /// <param name="name">班级名称</param>
        /// <returns>成功:true  失败：false </returns>
        public bool DelCls(string name)
        {
            int index = -1;
            for (int i = 0; i < numberofclass; i++)
                if (classArray[i].Name == name)
                {
                    index = i;
                    break;
                }
            if (index == -1)
                return false;
            if (index == numberofclass - 1)
            {
                classArray[index] = null;
                numberofclass--;
                return true;
            }
            for (int i = index; i < numberofclass; i++)
            {
                classArray[i] = classArray[i + 1];
            }
            numberofclass--;
            return true;
        }

        /// <summary>
        /// 索引
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public clsClass this[int index]
        {
            get {
                if (index < numberofclass && index >= 0)
                    return classArray[index];
                return null;
            }
        }
        /// <summary>
        /// 获取系信息
        /// </summary>
        /// <returns></returns>
        public string DepartmentInformation()
        {
            string str = "";
            str = str + "   系名称：" + this.Name;
            str = str + "   班级数量：" + this.NumberOfClasses;
            str = str + "   学生数：" + this.NumberOfStudent;
            str = str + "   男同学数：" + this.NumberOfBoy;
            str = str + "   女同学数：" + this.NumberOfGirl + "\n";
            return str;
        }
    }
}
