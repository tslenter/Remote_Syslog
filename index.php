<?php
/*
License:
“Remote Syslog” is a free application what can be used to view syslog messages.
Copyright (C) 2017 Tom Slenter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

For more information contact the author:
Name author: Tom Slenter
E-mail: info@remotesyslog.com
*/
?>

<html>
	<head>
		<title>Remote Syslog: v1.1.3</title>
	</head>
	<body bgcolor="#000000"; style="color:#00FF00">

        <script src="jquery-latest.js"></script>

        <script>
        $(document).ready(function() {
                $("#responsecommand").load("loaddata.php");
                var refreshId = setInterval(function() {
                $("#responsecommand").load('loaddata.php?randval='+ Math.random());
        }, 100);
        $.ajaxSetup({ cache: false });
        });

        </script>
		<div align="left" >
                                <?php echo "<font color=\"white\">Remote Syslog v1.1.3 by T.Slenter<br>More info: </font>"; ?><a href="https://www.remotesyslog.com/" target="_blank" style="color: #FFFF00">https://www.remotesyslog.com/</a>
				<hr width="100%" noshade></hr>
                                <div id="responsecommand"; style="overflow: scroll; overflow-y:hidden; height: 507px; width: 100%;" >
                                </div>
				<hr width="100%" noshade></hr>
				<?php echo "<font color=\"white\"></font>"; ?>
		</div>
		<div align="center">
                                <?php if (isset($_POST['button4'])) { header('Location: remote_syslog'); } ?>
                                <?php if (isset($_POST['button1'])) { exec('logger -n 127.0.0.1 -d "This is a UDP test message!"; logger -T -P 514 -n 127.0.0.1 "This is a TCP test message!"'); } ?>
                                <?php if (isset($_POST['button2'])) { exec('rm -rf /var/log/remote_syslog/remote_syslog.log.*'); } ?>
				<?php if (isset($_POST['button3'])) { header('Location: https://www.remotesyslog.com/License'); } ?>
                                        <form action="" method="post">
                                                <button type="submit" name="button4" style="width:150px; height:30px; margin-right:5;">Syslog archive</button>
                                                <button type="submit" name="button1" style="width:150px; height:30px; margin-right:5;">Send test message</button>
                                                <button type="submit" name="button2" style="width:150px; height:30px; margin-right:5;">Clear live log archive</button>
                                                <button type="submit" name="button3" style="width:150px; height:30px;">License</button>
                                </form>
				<?php echo "<font color=\"white\">Donate Bitcoin: 1MbvHNDmj5fYQ9fQEdMJH7HM4c8DfVLb66</font><br>"; ?>
                </div>
 	</body>
</html>
