using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.ComponentModel;

namespace Guarded_Suspension
{
    public partial class Form1 : Form
    {
        PatientQueue queue=new PatientQueue();

        BackgroundWorker pushThread= new BackgroundWorker();
        BackgroundWorker pullThread = new BackgroundWorker();
        int pushCount = 0;
        int pullCount = 0;

        public Form1()
        {
            InitializeComponent();
            label2.Text =queue.Lenght.ToString();
            InitializeBackgroundWorker();
        }
        private void InitializeBackgroundWorker()
        {
            pushThread.DoWork +=new DoWorkEventHandler(Push);
            pullThread.DoWork += new DoWorkEventHandler(Pull);

            pushThread.RunWorkerCompleted +=new RunWorkerCompletedEventHandler(Completed);
            pullThread.RunWorkerCompleted += new RunWorkerCompletedEventHandler(Completed);
        }
        void Push(object sender, DoWorkEventArgs e)
        {
            PatientQueue queue = (PatientQueue)e.Argument;
            TimeSpan time = new TimeSpan(Convert.ToInt64(pushTime.Value));
            Thread.Sleep(time);
            queue.Push(new Object());
            e.Result=queue;        
        }
        void Pull(object sender, DoWorkEventArgs e)
        {
            PatientQueue queue = (PatientQueue)e.Argument;
            TimeSpan time = new TimeSpan(Convert.ToInt64(pullTime.Value));
            Thread.Sleep(time);
            queue.Pull();
            e.Result = queue; 
        }

        void Completed(object sender, RunWorkerCompletedEventArgs e)
        {
            queue = (PatientQueue)e.Result;         
            label2.Text =  queue.Lenght.ToString();
            progressBar1.Value = queue.Lenght;
            Thread.Sleep(500);
            pull.Enabled = true;
            push.Enabled = true;  
        }
       
        private void push_Click(object sender, EventArgs e)
        {
            push.Enabled = false;
            pushCount++;
            label5.Text = pushCount.ToString();
            pushThread.RunWorkerAsync(queue);
                
        }

        private void pull_Click(object sender, EventArgs e)
        {
            pull.Enabled = false;
            pullCount++;
            label6.Text = pullCount.ToString() ;
            pullThread.RunWorkerAsync(queue);
           
        }
    }
}
