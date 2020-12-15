package Show;


import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.junit.Assert.assertSame;

public class EquationTest {

    AddEquation add;
    SubEquation sub;
    @Before
    public void setUp() throws Exception {
        add= new AddEquation();
        sub= new SubEquation();
    }
    AddEquation add2 = new AddEquation();
    SubEquation sub2 = new SubEquation();

    @Test
    public void testNull(){
        assertNotNull("加法算式不是空对象",add);
        assertNotNull("减法算式不是空对象",sub);
    }
    @Test
    public void testEquals1(){
        assertNotSame("加法算式不是同一个对象",add,add2);
        assertNotSame("减法算式不是同一个对象",sub,sub2);
    }
    @Test
    public void testEquals2(){
        assertFalse("加法算式不是相等的对象",add.equals(add2));
        assertFalse("减法算式不是相等的对象",sub.equals(sub2));
    }
    @Test
    public void testEquals3(){
        add2=add;
        assertSame("是同一个对象",add,add2);
    }
}
