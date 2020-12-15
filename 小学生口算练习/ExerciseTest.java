package Show;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class ExerciseTest {

    Exercise exer;

    @Before
    public void setUp() throws Exception {
        exer= new Exercise(50);
    }
    Exercise exer2= new Exercise(50);

    @Test
    public void testNull(){
        assertNotNull("习题集不是空对象",exer);
    }

    @Test
    public void testEquals1(){
        assertNotSame("习题集不是同一个对象",exer,exer2);
    }
    @Test
    public void testEquals2(){
        assertFalse("习题集不是相等的对象",exer.equals(exer2));

    }
    @Test
    public void testEquals3(){
        exer2=exer;
        assertSame("习题集是同一个对象",exer,exer2);
    }


}
