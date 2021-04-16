<?php
// require 'sweetAlert/src/sweetalert2.js';
  include 'sub/db.php';
  include 'func.php';

  // Import PHPMailer classes into the global namespace
use PHPMailer\PHPMailer\PHPMailer;

// Include PHPMailer library files
require 'PHPMailer-master/src/Exception.php';
require 'PHPMailer-master/src/PHPMailer.php';
require 'PHPMailer-master/src/SMTP.php';

// Create an instance of PHPMailer class
$mail = new PHPMailer();

// SMTP configuration
$mail->isSMTP();
$mail->Host = 'smtp.gmail.com';
$mail->SMTPAuth = true;
$mail->Username = 'arpitp16197@gmail.com';
$mail->Password = 'A8347087767';
$mail->SMTPSecure = 'tls';
$mail->Port = 587; ?>
<?php
if (isset($_POST['submit'])) {
    // Sender info
    $mail->setFrom('arpitp16197@gmail.com', 'Arpit');
    //  $mail->addReplyTo('arpitp16197@gmail.com', 'Arpit');

    // Add a recipient
    $mail->addAddress($_POST['email']);

    // Email subject
    $mail->Subject = 'Send Email via Arpit Patel';

    // Set email format to HTML
    $mail->isHTML(true);

    // Email body content
    $mailContent = ' 
This Mail from Arpit Patel. I got Your Message.';
    $mail->Body = $mailContent;

    // Send email
    if (!$mail->send()) {
        echo 'Message could not be sent. Mailer Error: '.$mail->ErrorInfo;
    }
}?>
<html>

<head>
	<title>Arpit Patel</title>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
	<meta name="description" content="" />
	<meta name="keywords" content="" />
	<link rel="icon" type="image/png" href="images/logoP.png">
	<link rel="stylesheet" href="assets/css/main.css" />
</head>

<body class="is-preload">

	<!-- Header -->
	<header id="header">
		<a class='logo'>Arpit Patel</a>
		<nav>
			<a href="#menu">Menu</a>
		</nav>
	</header>

	<!-- Nav -->
	<nav id="menu">
		<ul class="links">
			<li><a href="#banner">Home</a></li>
			<li><a href="#projects">Projects</a></li>
			<li><a href="#technicalskills">Technical Skills</a></li>
			<li><a href="#contactme">Contact Me</a></li>
			<li><a href="#cta">About Me</a></li>
		</ul>
	</nav>



	<!-- Banner -->
	<section id="banner">
		<div class="inner">
			<p><b>Arpit Patel</b><br />Web Developer</p>
			<ul class="plain">
				<li><a href="images/Arpit-Resume.pdf" style="text-decoration:none;" download>Download Resume</a>
				</li>
			</ul>
		</div>
		<video autoplay muted loop src="images/banner.mp4"></video>
	</section>

	<!-- Highlights -->
	<section class="wrapper" id="technicalskills">
		<div class="inner">
			<header class="special">
				<h2>Technical Skills</h2>
			</header>
			<div class="highlights">
				<section>
					<div class="content">
						<header>
							<h1><b>LANGUAGES</b></h1>
						</header>
						<p> HTML5<br>CSS3</br>JAVASCRIPT<br>PHP</br>JAVA<br>C++</br></p>
					</div>
				</section>
				<section>
					<div class="content">
						<header>
							<h1><b>FRAMEWORKS</b></h1>
						</header>
						<p>
							BOOTSTRAP<br>LARAVEL<br>WORDPRESS<br>YII</p>
					</div>
				</section>
				<section>
					<div class="content">
						<header>
							<h1><b>TOOLS</b></h1>
						</header>
						<p>
							VISUAL STUDIO CODE<br>VISUAL STUDIO<br>NETBEANS<br>ANDROID
							STUDIO<br>ECLIPSE<br>TRELLO<br>GITHUB<br>SUBLIME
						</p>
					</div>
				</section>


			</div>
		</div>
	</section>

	<!-- CTA -->
	<section id="cta" class="wrapper">
		<div class="inner">
			<h2>About Me</h2>
			<p>I am <b>Arpit Patel</b>.Exceptionally creative and dependable <b>Entry Level Web Developer</b>
				with a stellar customer service record and superb work ethic. Broadly
				and deeply knowledgeable in a wide variety of computer languages as well as
				the principles and techniques of website construction and maintenance.
				Highly adept at conveying complex technical information to a variety of professional
				and lay audiences in a clear and understandable manner.Additionaly,I have different skills like
				<b>Problem-Solving, Team-Work, Consistency, Persistent and Patience with Perfection.</b>I like to work
				with
				<b>PHP, HTML, CSS and JAVASCRIPT.</b>
			</p>
		</div>
	</section>

	<!-- Testimonials -->
	<section class="wrapper" id="projects">
		<div class="inner">
			<header class="special">
				<h2>PROJECTS</h2>
			</header>
			<div class="testimonials">
				<section>
					<div class="content">
						<p>It is Diamond selling website.In this website, I have different module and features.
							Like I have different type of diamonds and deeply details about it and online purchase.
						</p>
						<ul class="plain">
							<li><a href="projects.php" style="text-decoration:none; color:black;"><i
										class="fa fa-info">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</i>See
									More</a>
							</li>
							<li><a href="https://github.com/Ap2318/Diamond/tree/master"
									style="text-decoration:none; color:black;"><i
										class="fa fa-github">&nbsp;&nbsp;&nbsp;&nbsp;</i>Source Code</a>
							</li>
						</ul>
						<div class="author">
							<div class="image">
								<img src="images/d1.png" alt="" />
							</div>
							<h3><a href="projects.php">Diamond</a></h3>
						</div>
					</div>
				</section>
				<section>
					<div class="content">
						<p>This is also website called ART-O-MEDIA.It is online artist selling website.we are
							providing
							different type of artist for different events like wedding and party. </p>
						<ul class="plain">
							<li><a href="projects.php" style="text-decoration:none; color:black;"><i
										class="fa fa-info">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</i>See
									More</a>
							</li>
							<li><a href="https://github.com/Ap2318/Diamond/tree/master"
									style="text-decoration:none; color:black;"><i
										class="fa fa-github">&nbsp;&nbsp;&nbsp;&nbsp;</i>Source Code</a>
							</li>
						</ul>
						<div class="author">
							<div class="image">
								<img src="images/artist.jpg" alt="" />
							</div>
							<h3><a href="projects.php">art-o-media</a></h3>
						</div>
					</div>
				</section>
				<section>
					<div class="content">
						<p>It is Diamond selling application.In this application, I have different module and
							features.
							Like I have different type of diamonds and deeply details about it and online purchase.
						</p>
						<ul class="plain">
							<li><a href="projects.php" style="text-decoration:none; color:black;"><i
										class="fa fa-info">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</i>See
									More</a>
							</li>
							<li><a href="https://github.com/login" style="text-decoration:none; color:black;"><i
										class="fa fa-github">&nbsp;&nbsp;&nbsp;&nbsp;</i>Source Code</a>
							</li>
						</ul>
						<div class="author">
							<div class="image">
								<img src="images/logo.jpg" alt="" />
							</div>
							<h3><a href="projects.php">Diamond</a></h3>
						</div>
					</div>
				</section>
			</div>
		</div>

		<a href="projects.php" style="align-center;">See
			More Projects..</a>
	</section>
	<div id='contactme' style="padding:40px; margin:20px;">
		<header class="special">
			<h2>contact me</h2>
		</header>
		<div class="row">
			<div class="col-75">
				<div class="container">
					<form method="post" enctype="multipart/form-data">
						<div class="row" style=" margin-right:200px;">
							<div class="col-50">
								<label for="fname">Name</label>
								<input type="text" id="fname" name="contact_person" value=""
									placeholder="Enter contact person">
								<div class="row">
									<div class="col-50">
										<label for="email"> Email</label>
										<input type="text" id="email" name="email" value="" placeholder="@example.com"
											required="">
									</div>
									<div class="col-50">
										<label for="msg">Message</label>
										<textarea id="msg" name="msg" value="" placeholder="" required></textarea>
									</div>
								</div>
								<div class="" style="margin:30px;">
									<input type="submit" name="submit" value="Submit" placeholder="" required>
								</div>
							</div>
					</form>
				</div>
			</div>
		</div>
		<section>
			<p><b>Contact</b><br />
				Name : Arpit Patel<br />
				Email : arpitp16197@gmail.com<br />
				Phone No. : +1 438-336-2339</p>
		</section>
		<section>

			<ul class="plain">
				<li><a href="https://linkedin.com/in/arpitpatel2323" style="text-decoration:none; color:black;"><i
							class="icon fa-linkedin">&nbsp;</i>LinkedIn</a>
				</li>
				<li><a href="https://github.com/Ap2318" style="text-decoration:none; color:black;"><i
							class="icon fa-github">&nbsp;</i>Github</a></li>
			</ul>
			<iframe
				src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2796.781075621583!2d-73.65072128504862!3d45.494353139453004!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x4cc919e8cfa172c1%3A0x8fed41dbb5315f65!2s5175%20Avenue%20de%20Courtrai%2C%20Montr%C3%A9al%2C%20QC%20H3W%200A9!5e0!3m2!1sen!2sca!4v1618524661225!5m2!1sen!2sca"
				width="300" height="100" style="border:0;" allowfullscreen="" loading="lazy"></iframe>
		</section>
	</div>

	</div>

	<!-- Footer -->
	<footer id="footer">
		<div class="inner">
			<div class="content">
				<section>
					<p><b>Contact</b><br />
						Name : Arpit Patel<br />
						Email : arpitp16197@gmail.com<br />
						Phone No. : +1 438-336-2339</p>

				</section>
				<section>
					<h4>Menu</h4>
					<ul class="alt">
						<li><a href="#banner">Home</a></li>
						<li><a href="#projects">Projects</a></li>
						<li><a href="#technicalskills">Technical Skills</a></li>
						<li><a href="#contactme">Contact Me</a></li>
						<li><a href="#cta">About Me</a></li>

					</ul>
				</section>
				<section>

					<ul class="plain">
						<li><a href="https://linkedin.com/in/arpitpatel2323"><i
									class="icon fa-linkedin">&nbsp;</i>LinkedIn</a>
						</li>
						<li><a href="https://github.com/Ap2318"><i class="icon fa-github">&nbsp;</i>Github</a></li>
					</ul>
				</section>
			</div>
			<div class="copyright">
				@2021 Arpit Patel
			</div>
		</div>
	</footer>

	<!-- Scripts -->
	<script src="assets/js/jquery.min.js"></script>
	<script src="assets/js/browser.min.js"></script>
	<script src="assets/js/breakpoints.min.js"></script>
	<script src="assets/js/util.js"></script>
	<script src="assets/js/main.js"></script>

</body>

</html>