package controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



import action.AnimalAction;
import action.FarmAction;
import entity.AnimalEntity;
import entity.FarmEntity;


/**
 * Servlet implementation class DisplayServlet
 */
@WebServlet("/DisplayServlet")
public class DisplayServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DisplayServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		
		String countrySearch = null;
		countrySearch=request.getParameter("country");
		String farmerSearch = null;
		farmerSearch=request.getParameter("farmer");
		
		
		//String lastNameTosearchFor = request.getParameter("lastname");
		//String Id=request.getParameter("Id");
		
		ArrayList<FarmEntity> farmList = null;
		
		if(countrySearch==null&&farmerSearch==null) {
			farmList = FarmAction.getListOfAllFarm();
		}else if(countrySearch!=null&&farmerSearch==null) {
			farmList = FarmAction.getListByCountry(countrySearch);
		}else if(countrySearch==null&&farmerSearch!=null) {
			farmList = FarmAction.getListByFarmer(farmerSearch);
		}
		
			
		
		request.setAttribute("myFarmList", farmList);	
		
		request.getRequestDispatcher("displayFarm.jsp").forward(request, response);
		
		
		
	}


	

}
