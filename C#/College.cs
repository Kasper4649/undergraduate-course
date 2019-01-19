using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test4
{
    class College
    {
        public string Name="";
        private int numberofdepartment = 0;
        private Department[] deparray = new Department[5];
       
        /// <summary>
       /// 系的数量
       /// </summary>
        public int NumberOfDeparment
        {
            get {
                return numberofdepartment;
            }
        }
        /// <summary>
        /// 全院学生人数
        /// </summary>
        public int NumberOfStudents
        {
            get
            {
                int sum = 0;
                for (int i = 0; i < numberofdepartment; i++)
                {
                    sum += deparray[i].NumberOfStudent;
                }
                return sum;
            }
        }
        /// <summary>
        /// 全学院男同学人数
        /// </summary>
        public int NumberOfBoy
        {
            get {
                int sum = 0;
                for (int i = 0; i < numberofdepartment; i++)
                    sum += deparray[i].NumberOfBoy;
                return sum;
            }
        }
        /// <summary>
        /// 全学院女同学人数
        /// </summary>
        public int NumberOfGirl
        {
            get
            {
                int sum = 0;
                for (int i = 0; i < numberofdepartment; i++)
                    sum += deparray[i].NumberOfGirl;
                return sum;
            }
        }
        /// <summary>
        /// 索引
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public Department this[int index]
        {
            get
            {
                if (index < 0 || index >numberofdepartment) 
                    return null;
                return deparray[index];
            }
        }
        /// <summary>
        /// 删除一个系对象
        /// </summary>
        /// <param name="depobj"></param>
        /// <returns></returns>
        public bool DelDep(Department depobj)
        {
            int index = -1;
            for (int i = 0; i < numberofdepartment; i++)
            {
                if (deparray[i] == depobj)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                return false;
            if (index == numberofdepartment - 1)
            {
                deparray[index] = null;
                numberofdepartment--;
                return true;
            }
            for (int i = index; i < numberofdepartment; i++)
                deparray[i] = deparray[i + 1];
            numberofdepartment--;
            return true;
        }

        /// <summary>
        /// 根据系的名字删除系对象
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public bool DelDep(string name)
        {
            Department depobj = null;
            for (int i = 0; i < numberofdepartment; i++)
                if (deparray[i].Name == name)
                    depobj=deparray[i];
            return DelDep(depobj);
        }

        /// <summary>
        /// 增加一个系对象
        /// </summary>
        /// <param name="depobj"></param>
        /// <returns>成功 true    失败 false</returns>
        public bool AddDep(Department depobj)
        {
            if (numberofdepartment == deparray.Length)
                return false;
            deparray[numberofdepartment] = depobj;
            numberofdepartment++;
            return true;
        }
        public override string ToString()
        {
            string str = "";
            str = "学院名称：" + Name+"   系数量："+NumberOfDeparment.ToString()+"  全院学生人数："+NumberOfStudents.ToString();
            str = str + "  男同学人数：" + NumberOfBoy.ToString() + "  女同学人数：" + NumberOfGirl.ToString() +"\n";
            return str;
        }
    }
}
