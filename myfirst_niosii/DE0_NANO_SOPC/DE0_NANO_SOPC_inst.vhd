	component DE0_NANO_SOPC is
		port (
			clk_clk                            : in  std_logic                    := 'X'; -- clk
			pio_led_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component DE0_NANO_SOPC;

	u0 : component DE0_NANO_SOPC
		port map (
			clk_clk                            => CONNECTED_TO_clk_clk,                            --                         clk.clk
			pio_led_external_connection_export => CONNECTED_TO_pio_led_external_connection_export  -- pio_led_external_connection.export
		);

