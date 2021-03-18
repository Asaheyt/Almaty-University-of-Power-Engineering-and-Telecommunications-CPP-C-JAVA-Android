import javax.swing.JApplet;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JButton;

public class DrawBalls2 extends JApplet implements ActionListener {
    private static final long serialVersionUID = 1L;

    int r1=1,r2=1,r3=1; //diametr up to 50 pixels
    int dx1=1,dx2=10,dx3=3; //speed
    JButton susp1,st1,susp2,st2,susp3,st3;

    class ThrDraw extends Thread {
        int r,dx,k;
        Graphics g;
        public ThrDraw(int diam, int ddx, Graphics gg, int kk){
            r=diam;
            dx=ddx;
            g=gg;
            k=kk;
        }
        public void paintg(){
            g.setColor(Color.white);
            g.fillOval(getWidth()/4*k-r/2,getHeight()/2-r/2,r,r);
            r+=dx;
            if ((r>=100) || (r<=1))
                dx*=-1;
            g.setColor(Color.blue);
            g.fillOval(getWidth()/4*k-r/2,getHeight()/2-r/2,r,r);
        }
        public void run(){
            while (true){
                paintg();
                try {
                    Thread.sleep(100);
                }
                catch (InterruptedException e) {
                }
            }
        }
    }
    ThrDraw MyThr1,MyThr2,MyThr3;

    public DrawBalls2() throws HeadlessException {
    }

    public void start(){
    }

    public void init(){
        getGraphics().setColor(Color.white);
        setSize(new Dimension(600,400));
        susp1 = new JButton ("Приостановить поток1");
        st1 = new JButton ("Запустить поток1");
        susp2 = new JButton ("Приостановить поток2");
        st2 = new JButton ("Запустить поток2");
        susp3 = new JButton ("Приостановить поток3");
        st3 = new JButton ("Запустить поток3");
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.add(susp1);
        c.add(susp2);
        c.add(susp3);
        c.add(st1);
        c.add(st2);
        c.add(st3);
        susp1.addActionListener(this);
        st1.addActionListener(this);
        susp2.addActionListener(this);
        st2.addActionListener(this);
        susp3.addActionListener(this);
        st3.addActionListener(this);
        c.setBackground(Color.white);
        c.setForeground(Color.green);
        MyThr1=new ThrDraw(r1,dx1,getGraphics(),1);
        MyThr2=new ThrDraw(r2,dx2,getGraphics(),2);
        MyThr3=new ThrDraw(r3,dx3,getGraphics(),3);
        MyThr1.start();
        MyThr2.start();
        MyThr3.start();
    }


    public void paint(Graphics g){
        super.paint(g);
        st1.updateUI();
        susp1.updateUI();
        st2.updateUI();
        susp2.updateUI();
        st3.updateUI();
        susp3.updateUI();
    }

    public void actionPerformed(ActionEvent e) {
        String str = e.getActionCommand();
        if (str.equals("Приостановить поток1"))
            MyThr1.suspend();
        if (str.equals("Запустить поток1"))
            MyThr1.resume();
        if (str.equals("Приостановить поток2"))
            MyThr2.suspend();
        if (str.equals("Запустить поток2"))
            MyThr2.resume();
        if (str.equals("Приостановить поток3"))
            MyThr3.suspend();
        if (str.equals("Запустить поток3"))
            MyThr3.resume();

    }

}