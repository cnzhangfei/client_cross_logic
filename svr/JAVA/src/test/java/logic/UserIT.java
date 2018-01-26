/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logic;

import org.junit.After;
import org.junit.AfterClass;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 *
 * @author ShiHua
 */
public class UserIT {

    public UserIT() {
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
     * Test of decry method, of class User.
     */
    @Test
    public void testDecry() {
        System.out.println("decry");
        String msg = "123";
        User instance = new User();
        String expResult = "123";
        String result = instance.decry(msg);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.

    }

    /**
     * Test of encry method, of class User.
     */
    @Test
    public void testEncry() {
        System.out.println("encry");
        String msg = "";
        User instance = new User();
        String expResult = "";
        String result = instance.encry(msg);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.

    }

    /**
     * Test of construct method, of class User.
     */
    @Test
    public void testConstruct() {
        System.out.println("construct");
        String id = "";
        User instance = new User();
        User expResult = null;
        User result = instance.construct(id);
        assertFalse(result == expResult);
        // TODO review the generated test code and remove the default call to fail.

    }

    /**
     * Test of instance method, of class User.
     */
    @Test
    public void testInstance() {
        System.out.println("instance");
        String id = "";
        User instance = new User();
        Entity expResult = null;
        Entity result = instance.instance(id);
        assertFalse(expResult == result);
        // TODO review the generated test code and remove the default call to fail.

    }

    /**
     * Test of excute method, of class User.
     */
    @Test
    public void testExcute() {
        System.out.println("excute");
        String action = "";
        String content = "";
        User instance = new User();
        String expResult = null;
        String result = instance.excute(action, content);
        System.out.println(result);
        assertTrue(null == result);
        // TODO review the generated test code and remove the default call to fail.

    }

    /**
     * Test of Init method, of class User.
     */
    @Test
    public void testInit() {
        System.out.println("Init");
        InitRequest req = null;
        User instance = new User();
        InitResponse expResult = null;
        InitResponse result = instance.Init(req);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.

    }

}
