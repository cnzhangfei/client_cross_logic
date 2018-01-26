/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logic;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

/**
 *
 * @author ShiHua
 */
@RunWith(Suite.class)
@Suite.SuiteClasses({logic.UserIT.class, logic.InitResponseIT.class, logic.UserInformationIT.class, logic.InitRequestIT.class, logic.AnonymousIT.class, logic.JsonMappingIT.class, logic.EntityIT.class})
public class LogicITSuite {

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }

    @Before
    public void setUp() throws Exception {
    }

    @After
    public void tearDown() throws Exception {
    }

}
