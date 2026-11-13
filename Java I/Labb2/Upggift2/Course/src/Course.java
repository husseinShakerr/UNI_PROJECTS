import static java.lang.StringTemplate.STR;

public class Course {
   private String name, points, code, description;

   public String getName(){
       return name;
   }
   public void setName(String name){
       this.name = name;
   }

    public String getPoints() {
        return points;
    }

    public void setPoints(String points) {
        this.points = points;
    }

    public String getCode(){
       return code;
    }

    public void setCode(String code){
       this.code = code;
    }

    public String getDescription(){
       return description;
    }

    public void setDescription(String description){
       this.description = description;
    }

    public void print(){
        System.out.println(STR."""
                Name: \{name}
                Code: \{code}
                Points: \{points}
                Description: \{description}
                """);
    }
}