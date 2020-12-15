package Show;


import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot;
import org.jfree.chart.title.TextTitle;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainGUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JPanel panelCenter, panelSouth;
	private JTextField tEquation[]; //文本框用来显示算式
	private JTextField tAnswer[]; //显示输入算式的答案
	private JTextField Answer[]; //显示输入算式的答案
	private JButton preButton, nextButton; //翻页按钮
	private JLabel pageIndex; //显示第几页
	private int equationCount; //算式的数量
	private int pages, currentPage;//总的页数，当前显示的页数
	private Exercise exercise;//习题类
	private Answer answer;//答案类
	private JButton check; //批改按钮
	private JLabel labelResult; //显示批改结果

	private final int PAGE_SIZE = 50; //每一页显示的算式数量


	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainGUI frame = new MainGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


	public MainGUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(300, 300, 750, 450);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		setResizable(false); //窗口大小不能改变
		init();//自定义的初始化方法
	}

	/**
	 * 自定义初始化方法
	 */
	private void init() {
		JMenuBar menuBar = new JMenuBar();//菜单条
		setJMenuBar(menuBar);
		JMenu menuOnline = new JMenu("在线练习"); //添加菜单
		menuBar.add(menuOnline);
		//加法菜单项
		JMenuItem onlineAdd = new JMenuItem("加法算式练习");
		onlineAdd.setActionCommand("onlineAdd");//设计菜单项单击事件
		menuOnline.add(onlineAdd);
		onlineAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				online(arg0);//自定义响应方法
			}
		});//菜单项的事件监听程序

		//减法菜单项
		JMenuItem onlineSub = new JMenuItem("减法算式练习");
		onlineSub.setActionCommand("onlineSub");
		menuOnline.add(onlineSub);
		onlineSub.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				online(arg0);//自定义响应方法
			}
		});

		//混合运算菜单项
		JMenuItem onlineMix= new JMenuItem("混合算式练习");
		onlineMix.setActionCommand("onlineMix");
		menuOnline.add(onlineMix);
		onlineMix.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				online(arg0);//自定义响应方法
			}
		});

		JMenu menuExit = new JMenu("退出");
		menuBar.add(menuExit);
		JMenuItem exit = new JMenuItem("退出");
		menuExit.add(exit);
		exit.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}

		});


		//答题区面板
		panelCenter = new JPanel();
		//panelCenter.setBackground(Color.PINK);
		//批改区面板
		panelSouth = new JPanel();
		//panelSouth.setBackground(Color.PINK);
		FlowLayout flowLayout = (FlowLayout)panelSouth.getLayout();//面部布局管理器，南区
		flowLayout.setAlignment(FlowLayout.LEFT); //居左对齐
		contentPane.add(BorderLayout.CENTER, panelCenter); //添加到框架中
		contentPane.add(BorderLayout.SOUTH, panelSouth);

		//初始化答题区
		tEquation = new JTextField[PAGE_SIZE]; //显示算式的文本框
		tAnswer = new JTextField[PAGE_SIZE]; //初始化答案的文本框
		Answer = new JTextField[PAGE_SIZE]; //初始化答案的文本框
		for(int i = 0; i < PAGE_SIZE; i++) {
			tEquation[i] = new JTextField(5); //文本框宽度5
			tEquation[i].setHorizontalAlignment(JTextField.RIGHT); //居右对其
			tEquation[i].setBackground(panelCenter.getBackground());
			tEquation[i].setBorder(null); //取消边框
			tEquation[i].setEditable(false); //设置不可编辑
			tAnswer[i] = new JTextField(3); //答案文本框
			Answer[i] = new JTextField(3); //答案文本框
			panelCenter.add(tEquation[i]);
			panelCenter.add(tAnswer[i]);
			panelCenter.add(Answer[i]);

			tEquation[i].setVisible(false);
			tAnswer[i].setVisible(false);
			Answer[i].setVisible(false);
		}
		preButton = new JButton("前一页");
		preButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				prePage();//自定义方法，前翻页
			}

		});

		nextButton = new JButton("后一页");
		nextButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				nextPage();//自定义方法，后翻页
			}

		});

		panelCenter.add(preButton);
		//页数
		pageIndex = new JLabel(); //显示页码标签
		panelCenter.add(pageIndex);
		panelCenter.add(nextButton);
		preButton.setVisible(false);
		nextButton.setVisible(false);

		//批改区
		check = new JButton("批改");
		check.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				check();//自定义批改方法
			}

		});

		labelResult = new JLabel(); //显示批改结果标签
		panelSouth.add(check);
		panelSouth.add(labelResult);
		check.setVisible(false);;
		labelResult.setVisible(false);
	}

	/**
	 * 自定义在线练习方法
	 */
	public void online(ActionEvent arg0) {
		if(arg0.getActionCommand() == "onlineAdd") {
			equationCount = Integer.parseInt(JOptionPane.showInputDialog("请输入加法算式数量")); //调用输入对话框
			exercise = new Exercise(equationCount);
			exercise.generateAddExercise();
		}
		else if(arg0.getActionCommand() == "onlineSub") {
			equationCount = Integer.parseInt(JOptionPane.showInputDialog("请输入减法算式数量"));
			exercise = new Exercise(equationCount);
			exercise.generateSubExercise();
		}
		else if(arg0.getActionCommand() == "onlineMix") {
			equationCount = Integer.parseInt(JOptionPane.showInputDialog("请输入混合算式数量"));
			exercise = new Exercise(equationCount);
			exercise.generateExercise();
		}

		answer = new Answer();
		for(int i = 0; i < equationCount; i++) {
			answer.add(-1); //初始化为-1
		}

		pages = (int)Math.ceil(equationCount * 1.0 / PAGE_SIZE); //当前算式的页数
		currentPage = 1;
		labelResult.setText(""); //批改结果，初始化为空
		update();//自定义刷新图形界面方法
	}

	/**
	 * 自定义刷新图形界面
	 */
	public void update() {
		//i,算式在习题中的序号；j，当前页面中算式的序号，即图形组件序号
		for(int i = (currentPage - 1) * PAGE_SIZE, j = 0; i < currentPage * PAGE_SIZE; i++, j++) {
			if(i < equationCount) {
				tEquation[j].setText(exercise.get(i).toString());
				tEquation[j].setBackground(panelCenter.getBackground());
				tEquation[j].setVisible(true);
				if(answer.get(i) != -1) {
					tAnswer[j].setText(Integer.toString(answer.get(i)));
				}
				else {
					tAnswer[j].setText("");
				}

				Answer[j].setText("");

				Answer[j].setVisible(true);
				tAnswer[j].setVisible(true);
			}
			else {
				tEquation[j].setVisible(false);
				tAnswer[j].setVisible(false);
				Answer[j].setVisible(false);
			}
		}
		//如果页数大于1，显示翻页按钮
		preButton.setVisible(pages > 1);//可用
		nextButton.setVisible(pages > 1);
		preButton.setEnabled(currentPage > 1);//不可用
		nextButton.setEnabled(currentPage < pages);
		pageIndex.setText(currentPage + " / " + pages);
		check.setVisible(true);
		labelResult.setVisible(true);
		//批改按钮直到最后一页才有效
		if(currentPage == pages) {
			check.setEnabled(true);
		}
		else {
			check.setEnabled(false);
		}
	}

	int count =0;
	//自定义翻页
	public void prePage() {
		for(int i = (currentPage - 1) * PAGE_SIZE, j = 0; i < currentPage * PAGE_SIZE; i++, j++) {
			if(i < equationCount && tAnswer[j].getText() != null && tAnswer[j].getText().length() > 0) {
				if(tAnswer[j].getText().matches("^[0-9]*$")) {  //正则表达式验证答案是否正确
					answer.set(i, Integer.parseInt(tAnswer[j].getText()));
				}
			}
		}
		currentPage--;
		update();
		if(count == 1) check();

	}

	public void nextPage() {
		for(int i = (currentPage - 1) * PAGE_SIZE, j = 0; i < currentPage * PAGE_SIZE; i++, j++) {
			if(i < equationCount && tAnswer[j].getText() != null && tAnswer[j].getText().length() > 0) {
				if(tAnswer[j].getText().matches("^[0-9]*$")) {
					answer.set(i, Integer.parseInt(tAnswer[j].getText()));
				}
			}
		}
		currentPage++;
		update();
		if(count == 1) check();

	}

	/**
	 * 自定义批改方法
	 */
	public void check() {
		count = 1;
		for(int i = (currentPage - 1) * PAGE_SIZE, j = 0; i < currentPage*PAGE_SIZE; i++, j++) {
			if(i < equationCount && tAnswer[j].getText() != null && tAnswer[j].getText().length() > 0) {
				if(tAnswer[j].getText().matches("^[0-9]*$")) {
					answer.set(i, Integer.parseInt(tAnswer[j].getText()));
				}
			}
		}
		Check ch = new Check();
		ch.check(exercise, answer);
		labelResult.setText("正确：" + ch.getRight() + "； 错误：" + ch.getWrong());
		drawPieChart(ch);

		for(int i = (currentPage - 1) * PAGE_SIZE, j = 0; i < currentPage * PAGE_SIZE; i++, j++) {
			if(i < equationCount) {
				Answer[j].setText(""+exercise.get(i).getResult());
				Answer[j].setBackground(panelCenter.getBackground());
				Answer[j].setVisible(true);
			}
			else {
				tEquation[j].setVisible(false);
			}
			if(ch.get(j) == 0)
			{
				tAnswer[j].setBorder(BorderFactory.createLineBorder(Color.RED));
			}
		}

	}
	
	/**
	 * 自定义方法，绘制批改结果的饼图
	 */
	public void drawPieChart(Check check) {
		DefaultPieDataset dataset = new DefaultPieDataset(); //饼图的数据集合
		dataset.setValue("Right:" + check.getRight(), check.getRight());
		dataset.setValue("Wrong:" + check.getWrong(), check.getWrong());
		JFreeChart chart = ChartFactory.createPieChart("批改结果", (PieDataset)dataset, false, false, false);
		PiePlot plot = (PiePlot)chart.getPlot();
		chart.setBackgroundPaint(Color.WHITE);
		plot.setForegroundAlpha(1.0f);
		plot.setCircular(true);
		Font font = new Font("黑体", Font.CENTER_BASELINE, 20);
		TextTitle title = chart.getTitle();
		title.setFont(font);
		chart.setTitle(title);
		ChartPanel cPanel = new ChartPanel(chart);
		JFrame f = new JFrame();
		f.setBounds(300, 300, 300, 300);
		f.add(cPanel);
		f.setVisible(true);
	}
}
