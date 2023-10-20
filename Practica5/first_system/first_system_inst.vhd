	component first_system is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			leds_external_connection_export : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n                   : in  std_logic                    := 'X'  -- reset_n
		);
	end component first_system;

	u0 : component first_system
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			leds_external_connection_export => CONNECTED_TO_leds_external_connection_export, -- leds_external_connection.export
			reset_reset_n                   => CONNECTED_TO_reset_reset_n                    --                    reset.reset_n
		);

