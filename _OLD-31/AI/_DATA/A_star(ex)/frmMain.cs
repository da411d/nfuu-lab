using System;
using System.IO;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace MazeSolverDemo
{
	public class frmMain : System.Windows.Forms.Form
	{
		Mehroz.MazeSolver m_Maze;
		int[,] m_iMaze;
		int m_iSize=50;
		int m_iRowDimensions=6;
		int m_iColDimensions=6;
		int iSelectedX, iSelectedY=5;

		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.Label lblPath;
		private System.Windows.Forms.GroupBox grpAction;
		private System.Windows.Forms.RadioButton bDraw;
		private System.Windows.Forms.RadioButton bFind;
		private System.Windows.Forms.Label lblPathCaption;
        private System.Windows.Forms.Button cmdReset;
		private System.Windows.Forms.Button cmdExit;
		private System.Windows.Forms.CheckBox chkDiagonal;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public frmMain()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.lblPath = new System.Windows.Forms.Label();
            this.grpAction = new System.Windows.Forms.GroupBox();
            this.bFind = new System.Windows.Forms.RadioButton();
            this.bDraw = new System.Windows.Forms.RadioButton();
            this.lblPathCaption = new System.Windows.Forms.Label();
            this.cmdReset = new System.Windows.Forms.Button();
            this.cmdExit = new System.Windows.Forms.Button();
            this.chkDiagonal = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.grpAction.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Location = new System.Drawing.Point(24, 16);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(311, 301);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            // 
            // lblPath
            // 
            this.lblPath.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPath.Location = new System.Drawing.Point(364, 208);
            this.lblPath.Name = "lblPath";
            this.lblPath.Size = new System.Drawing.Size(128, 16);
            this.lblPath.TabIndex = 3;
            // 
            // grpAction
            // 
            this.grpAction.Controls.Add(this.bFind);
            this.grpAction.Controls.Add(this.bDraw);
            this.grpAction.Location = new System.Drawing.Point(364, 16);
            this.grpAction.Name = "grpAction";
            this.grpAction.Size = new System.Drawing.Size(120, 104);
            this.grpAction.TabIndex = 4;
            this.grpAction.TabStop = false;
            this.grpAction.Text = "Action";
            // 
            // bFind
            // 
            this.bFind.Location = new System.Drawing.Point(8, 64);
            this.bFind.Name = "bFind";
            this.bFind.Size = new System.Drawing.Size(104, 24);
            this.bFind.TabIndex = 1;
            this.bFind.Text = "Find Path";
            this.bFind.CheckedChanged += new System.EventHandler(this.bFind_CheckedChanged);
            // 
            // bDraw
            // 
            this.bDraw.Checked = true;
            this.bDraw.Location = new System.Drawing.Point(8, 24);
            this.bDraw.Name = "bDraw";
            this.bDraw.Size = new System.Drawing.Size(104, 24);
            this.bDraw.TabIndex = 0;
            this.bDraw.TabStop = true;
            this.bDraw.Text = "Draw Walls";
            this.bDraw.CheckedChanged += new System.EventHandler(this.bDraw_CheckedChanged);
            // 
            // lblPathCaption
            // 
            this.lblPathCaption.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPathCaption.Location = new System.Drawing.Point(364, 192);
            this.lblPathCaption.Name = "lblPathCaption";
            this.lblPathCaption.Size = new System.Drawing.Size(100, 16);
            this.lblPathCaption.TabIndex = 5;
            this.lblPathCaption.Text = "Current Path";
            // 
            // cmdReset
            // 
            this.cmdReset.Location = new System.Drawing.Point(360, 250);
            this.cmdReset.Name = "cmdReset";
            this.cmdReset.Size = new System.Drawing.Size(104, 24);
            this.cmdReset.TabIndex = 6;
            this.cmdReset.Text = "Clear";
            this.cmdReset.Click += new System.EventHandler(this.cmdReset_Click);
            // 
            // cmdExit
            // 
            this.cmdExit.Location = new System.Drawing.Point(360, 280);
            this.cmdExit.Name = "cmdExit";
            this.cmdExit.Size = new System.Drawing.Size(104, 24);
            this.cmdExit.TabIndex = 8;
            this.cmdExit.Text = "Exit";
            this.cmdExit.Click += new System.EventHandler(this.cmdExit_Click);
            // 
            // chkDiagonal
            // 
            this.chkDiagonal.Location = new System.Drawing.Point(364, 144);
            this.chkDiagonal.Name = "chkDiagonal";
            this.chkDiagonal.Size = new System.Drawing.Size(112, 24);
            this.chkDiagonal.TabIndex = 9;
            this.chkDiagonal.Text = "Allow Diagonals";
            this.chkDiagonal.CheckedChanged += new System.EventHandler(this.chkDiagonal_CheckedChanged);
            // 
            // frmMain
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(498, 343);
            this.Controls.Add(this.chkDiagonal);
            this.Controls.Add(this.cmdExit);
            this.Controls.Add(this.cmdReset);
            this.Controls.Add(this.lblPathCaption);
            this.Controls.Add(this.grpAction);
            this.Controls.Add(this.lblPath);
            this.Controls.Add(this.pictureBox1);
            this.Name = "frmMain";
            this.Text = "A_Star";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.grpAction.ResumeLayout(false);
            this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			try
			{
				Application.Run(new frmMain());
			}
			catch(Exception exp)
			{
				System.Windows.Forms.MessageBox.Show("An unhandled exception '"+exp.Message+"' has occurred.", "Error");
			}
		}

		private void Form1_Load(object sender, System.EventArgs e)
		{
			m_Maze = new Mehroz.MazeSolver(m_iRowDimensions, m_iColDimensions);
			this.pictureBox1.Size=new System.Drawing.Size(m_iColDimensions*m_iSize+3, m_iRowDimensions*m_iSize+3);
			m_iMaze=m_Maze.GetMaze;
			this.lblPath.Visible=false;
			this.lblPathCaption.Visible=false;
		}

		private void pictureBox1_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
		{
			Graphics myGraphics = e.Graphics;
			for (int i=0;i<m_iRowDimensions;i++)
				for (int j=0;j<m_iColDimensions;j++)
				{
					// print grids
                        myGraphics.DrawRectangle(new Pen(Color.Black) , j*m_iSize, i*m_iSize, m_iSize, m_iSize);
					// print walls
					if ( m_iMaze[i,j]==1 )
						myGraphics.FillRectangle(new SolidBrush(Color.DarkGray) , j*m_iSize+1, i*m_iSize+1, m_iSize-1, m_iSize-1);
					//print path
					if ( m_iMaze[i,j]==100 )
						myGraphics.FillRectangle(new SolidBrush(Color.Cyan) , j*m_iSize+1, i*m_iSize+1, m_iSize-1, m_iSize-1);
				}
			//print ball
			myGraphics.FillEllipse(new SolidBrush(Color.Green), this.iSelectedX*m_iSize+5, this.iSelectedY*m_iSize+5, m_iSize-10, m_iSize-10);

		}

		private void pictureBox1_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			int iX=e.X/m_iSize;
			int iY=e.Y/m_iSize;
			if ( iX<m_iColDimensions && iX>=0 && iY<m_iRowDimensions && iY>=0)
			{
				if (this.bDraw.Checked==true)
				{
					m_iMaze=m_Maze.GetMaze;
					if (m_iMaze[iY,iX]==0) 
						m_iMaze[iY,iX]=1;
					else
						m_iMaze[iY,iX]=0;
					this.Refresh();
				}
				else
				{
					if (m_iMaze[iY,iX]==100)	//if path exists
					{
						//move step by step until the required position is achieved
						while (this.iSelectedX!=iX || this.iSelectedY!=iY)
						{
							m_iMaze[this.iSelectedY,this.iSelectedX]=0;

							if (this.iSelectedX-1>=0 && this.iSelectedX-1<m_iColDimensions && m_iMaze[this.iSelectedY, this.iSelectedX-1]==100)
								this.iSelectedX--;
							else if (this.iSelectedX+1>=0 && this.iSelectedX+1<m_iColDimensions && m_iMaze[this.iSelectedY, this.iSelectedX+1]==100)
								this.iSelectedX++;
							else if (this.iSelectedY-1>=0 && this.iSelectedY-1<m_iRowDimensions && m_iMaze[this.iSelectedY-1, this.iSelectedX]==100)
								this.iSelectedY--;
							else if (this.iSelectedY+1>=0 && this.iSelectedY+1<m_iRowDimensions && m_iMaze[this.iSelectedY+1, this.iSelectedX]==100)
								this.iSelectedY++;

							// move diagonal
							else if (this.iSelectedY+1>=0 && this.iSelectedY+1<m_iRowDimensions && this.iSelectedX+1>=0 && this.iSelectedX+1<m_iColDimensions && m_iMaze[this.iSelectedY+1, this.iSelectedX+1]==100)
							{	this.iSelectedX++;	this.iSelectedY++;	}
							else if (this.iSelectedY-1>=0 && this.iSelectedY-1<m_iRowDimensions && this.iSelectedX+1>=0 && this.iSelectedX+1<m_iColDimensions && m_iMaze[this.iSelectedY-1, this.iSelectedX+1]==100)
							{	this.iSelectedX++;	this.iSelectedY--;	}
							else if (this.iSelectedY+1>=0 && this.iSelectedY+1<m_iRowDimensions && this.iSelectedX-1>=0 && this.iSelectedX-1<m_iColDimensions && m_iMaze[this.iSelectedY+1, this.iSelectedX-1]==100)
							{	this.iSelectedX--;	this.iSelectedY++;	}
							else if (this.iSelectedY-1>=0 && this.iSelectedY-1<m_iRowDimensions && this.iSelectedX-1>=0 && this.iSelectedX-1<m_iColDimensions && m_iMaze[this.iSelectedY-1, this.iSelectedX-1]==100)
							{	this.iSelectedX--;	this.iSelectedY--;	}

							this.Refresh();
						}
					}
				}

			}
		}

		private void pictureBox1_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			int iY=e.Y/m_iSize;
			int iX=e.X/m_iSize;
			if ( iX<m_iColDimensions && iX>=0 && iY<m_iRowDimensions && iY>=0)
			{
				m_iMaze=m_Maze.GetMaze;
				if (this.bDraw.Checked==false)
				{
					int[,] iSolvedMaze=m_Maze.FindPath(iSelectedY,iSelectedX, iY,iX);
					if (iSolvedMaze!=null)
					{
						m_iMaze=iSolvedMaze;
						this.lblPath.Text=""+iSelectedY+","+iSelectedX+" to "+iY+","+iX;
					}
					else
						this.lblPath.Text="No Path Found";
					this.Refresh();
				}
			}
		}

		private void bDraw_CheckedChanged(object sender, System.EventArgs e)
		{
			m_iMaze=m_Maze.GetMaze;
			this.lblPath.Visible=false;
			this.lblPathCaption.Visible=false;
			this.Refresh();
		}

		private void bFind_CheckedChanged(object sender, System.EventArgs e)
		{
			this.m_Maze.AllowDiagonals=this.chkDiagonal.Checked;
			this.lblPath.Visible=true;
			this.lblPathCaption.Visible=true;
		}

		private void cmdReset_Click(object sender, System.EventArgs e)
		{
			m_Maze = new Mehroz.MazeSolver(m_iRowDimensions, m_iColDimensions);
			m_Maze.AllowDiagonals=this.chkDiagonal.Checked;
			m_iMaze=m_Maze.GetMaze;
			this.Refresh();
		}
		private void cmdExit_Click(object sender, System.EventArgs e)
		{
			this.Close();
		}

		private void chkDiagonal_CheckedChanged(object sender, System.EventArgs e)
		{
			m_Maze.AllowDiagonals=chkDiagonal.Checked; 
		}


	}



}
