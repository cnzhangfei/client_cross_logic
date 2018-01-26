/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logic;

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
public class EntityIT {

    public EntityIT() {
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
     * Test of instance method, of class Entity.
     */
    @Test
    public void testInstance() {
        System.out.println("instance");
        String id = "";
        Entity instance = new EntityImpl();
        Entity expResult = instance;
        Entity result = instance.instance(id);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of excute method, of class Entity.
     */
    @Test
    public void testExcute() {
        System.out.println("excute");
        String action = "";
        String parameter = "";
        Entity instance = new EntityImpl();
        String expResult = "";
        String result = instance.excute(action, parameter);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    public class EntityImpl implements Entity {

        @Override
        public Entity instance(String id) {
            return this;
        }

        @Override
        public String excute(String action, String parameter) {
            return "";
        }
    }

}
