import javax.swing.*;

public class Test{
    public static void main(String[] args){

        Course C1 = new Course();
        C1.setName("Discrete mathemathics");
        C1.setCode("MA098G");
        C1.setPoints("7.5 points");
        C1.setDescription("""
    Discrete mathematics is the study of mathematical structures that are discrete,
    separated or distinct; in contrast with calculus which deals with continuous change.""");
        C1.print();


        Course C2 = new Course();
        String Course_name = JOptionPane.showInputDialog("What´s the course name: ");
        String Course_points = JOptionPane.showInputDialog("How many points? ");
        String Course_code = JOptionPane.showInputDialog("What´s the code? ");
        String Course_description = JOptionPane.showInputDialog("Describe the course. ");

        C2.setName(Course_name);
        C2.setPoints(Course_points);
        C2.setCode(Course_code);
        C2.setDescription(Course_description);

        C2.print();
    }
}




