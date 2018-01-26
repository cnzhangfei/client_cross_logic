/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logic;

import java.lang.annotation.Annotation;
import org.junit.After;
import org.junit.AfterClass;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 *
 * @author ShiHua
 */
public class JsonMappingIT {

    public JsonMappingIT() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    /**
     * Test of name method, of class JsonMapping.
     */
    @Test
    public void testName() {
        System.out.println("name");
        JsonMapping instance = new JsonMappingImpl();
        String expResult = "";
        String result = instance.name();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of rexg method, of class JsonMapping.
     */
    @Test
    public void testRexg() {
        System.out.println("rexg");
        JsonMapping instance = new JsonMappingImpl();
        String expResult = "";
        String result = instance.rexg();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    public class JsonMappingImpl implements JsonMapping {

        public String name() {
            return "";
        }

        public String rexg() {
            return "";
        }

        @Override
        public Class<? extends Annotation> annotationType() {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
    }

}
