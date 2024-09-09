nmcli c add type wifi con-name {con-name} ifname wlp3s0 ssid {ssid}
nmcli con modify {con-name} wifi-sec.key-mgmt wpa-psk
nmcli con modify {con-name} wifi-sec.psk "wifi-password"
nmcli con up {con-name}
